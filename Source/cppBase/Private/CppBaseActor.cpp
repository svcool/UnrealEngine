#include "CppBaseActor.h"

//******************************************************************************************************************************************************
ACppBaseActor::ACppBaseActor()
{ // Sets default values	
	PrimaryActorTick.bCanEverTick = true;  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}
//******************************************************************************************************************************************************
void ACppBaseActor::Tick(float DeltaTime)
{  // Called every frame
	Super::Tick(DeltaTime);
}
//******************************************************************************************************************************************************
void ACppBaseActor::BeginPlay()
{  // Called when the game starts or when spawned
	Super::BeginPlay();

	InitialLocation = GetActorLocation();
	
	ShowActorInformation();
}
//******************************************************************************************************************************************************
void ACppBaseActor::ShowActorInformation() 
{
	UE_LOG(LogTemp, Display, TEXT("Instance name : %s"), *InstanceName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum : %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive : %i"), IsAlive);
}
//******************************************************************************************************************************************************
void ACppBaseActor::SinMovement()
{
	float SinusoidalPosition = Amplitude * FMath::Sin(GetWorld()->GetTimeSeconds() * Frequency);
	InitialLocation = InitialLocation + FVector(0.0f, 0.0f, SinusoidalPosition);
	SetActorLocation(InitialLocation); 
}
//******************************************************************************************************************************************************