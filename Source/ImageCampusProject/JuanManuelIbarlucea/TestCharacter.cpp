#include "TestCharacter.h"
#include "Components/InputComponent.h"
//#include "ImageCampusProject/HealthComponent.h"


// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Health Component
//	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


UHealthComponent_JM* ATestCharacter::GetHealthComponent() const
{
	return HealthComponent;
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void ATestCharacter::GetHit(int _damage) const
{
	//HealthComponent->GetHit(_damage);
}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAction(TEXT("GetHit"), IE_Pressed, this, &ThisClass::GetHit);
}

