#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"


class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FTransformStruct {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};


UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditInstanceOnly);
	float Amplitude = 70;
	UPROPERTY(EditInstanceOnly);
	float Frequency = 4;
	FVector InitialLocation = FVector::ZeroVector;

public:	
	
	ACppBaseActor();  // Sets default values for this actor's properties

	virtual void Tick(float DeltaTime) override;// Called every frame

	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* Mesh;

protected:
	
	virtual void BeginPlay() override;  // Called when the game starts or when spawned
	
	UPROPERTY(EditAnywhere);
	int EnemyNum = 20;
	
	UPROPERTY(EditInstanceOnly);
	bool IsAlive = true;

	FString InstanceName = this->GetName();

	UFUNCTION(BlueprintCallable)
	void ShowActorInformation();

	UFUNCTION(BlueprintCallable)
	void SinMovement();
};


