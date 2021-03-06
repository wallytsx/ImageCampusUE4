// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ImageCampusProjectCharacterVG.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "HealthComponentVG.h"
#include "GameModeBaseVG.h"

//////////////////////////////////////////////////////////////////////////
// AImageCampusProjectCharacter

AImageCampusProjectCharacterVG::AImageCampusProjectCharacterVG()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	HealthComponent = CreateDefaultSubobject<UHealthComponentVG>(TEXT("HealthComponent"));

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AImageCampusProjectCharacterVG::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ThisClass::Fire);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AImageCampusProjectCharacterVG::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AImageCampusProjectCharacterVG::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AImageCampusProjectCharacterVG::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AImageCampusProjectCharacterVG::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AImageCampusProjectCharacterVG::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AImageCampusProjectCharacterVG::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AImageCampusProjectCharacterVG::OnResetVR);
}

void AImageCampusProjectCharacterVG::BeginPlay()
{
	Super::BeginPlay();
	
	HealthComponent->OnDamageRecived.AddDynamic(this, &AImageCampusProjectCharacterVG::OnDamageRecived);
}

void AImageCampusProjectCharacterVG::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Called"));

	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();

	Transform.SetLocation(Location + GetActorForwardVector() * 100.0f);

	auto* Projectile = GetWorld()->SpawnActor<AICProjectile>(ProjectileClass.Get(), Transform);
}

void AImageCampusProjectCharacterVG::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AImageCampusProjectCharacterVG::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void AImageCampusProjectCharacterVG::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void AImageCampusProjectCharacterVG::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AImageCampusProjectCharacterVG::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AImageCampusProjectCharacterVG::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AImageCampusProjectCharacterVG::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

float AImageCampusProjectCharacterVG::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	return DamageAmount;
}

void AImageCampusProjectCharacterVG::OnDamageRecived(const AActor* DamageCauser)
{
	if(HealthComponent->Health <= 0)
	{
		KillPlayer();
		AGameModeBaseVG* GameMode = Cast<AGameModeBaseVG>(GetWorld()->GetAuthGameMode());
		if (GameMode != nullptr)
			GameMode->OnPlayerDeath(this);
	}
}