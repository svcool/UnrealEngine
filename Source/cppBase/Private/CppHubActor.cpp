#include "CppHubActor.h"

//******************************************************************************************************************************************************
// Sets default values
ACppHubActor::ACppHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh"); //������������ ����������
	SetRootComponent(Mesh); // ��������� � �������� ��������� ���������� ������
}
//******************************************************************************************************************************************************
void ACppHubActor::OnTimeToSpawn() 
{
	if (++CurrentTimerCount <= TotalTimerCount)
	{
		const FVector Location = GetActorLocation() + FVector(FMath::FRandRange(200.0f, 1000.0f), FMath::FRandRange(200.0f, 1000.0f), 0.0f); // ��������� ����������� �������� �� �����
		const FRotator Rotation = FRotator::ZeroRotator;
		ACppBaseActor* SpawnObject = GetWorld()->SpawnActor<ACppBaseActor>(CppClass, Location, Rotation);  // ��������� �� ����������� ������
		if (SpawnObject)
		{
			SpawnedObjects.Add(SpawnObject);
		}
	}
	else
	{
		GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
		for (int i = TotalTimerCount; i >=1; --i)
		{
			GetWorldTimerManager().SetTimer(DestroyTimerHandle, this, &ACppHubActor::OnTimeToDestroy, DestroyTimerRate, true);
		}
	}
}
//******************************************************************************************************************************************************
void ACppHubActor::OnTimeToDestroy() 
{
	if (!SpawnedObjects.IsEmpty())
	{
		SpawnedObjects.Top()->Destroy();
		SpawnedObjects.Pop();
	}
	else
	{
		GetWorldTimerManager().ClearTimer(DestroyTimerHandle);
	}
}
//******************************************************************************************************************************************************
void ACppHubActor::Tick(float DeltaTime)
{// Called every frame
	Super::Tick(DeltaTime);

}
//******************************************************************************************************************************************************
void ACppHubActor::BeginPlay()
{ // Called when the game starts or when spawned
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ACppHubActor ::OnTimeToSpawn, SpawnTimerRate, true);
		/*��� ��� ������(� ��� �� ������, ���������� � ����� ������� ������ � ���� ����������)
	    ������ � ������� ����� ���������� ������.
		������ �� �������, ������� ����� ���������� ��� ������������ �������.
		������� ������������ ������� � ��������.
		�������� ������ ��������� ��� ���.*/
}
//******************************************************************************************************************************************************


