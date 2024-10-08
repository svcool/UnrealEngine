// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "CppBaseActor.h"
#include "CppHubActor.generated.h"

class ACppBaseActor;

UCLASS()
class CPPBASE_API ACppHubActor : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* Mesh; // указтель на компонент

	virtual void Tick(float DeltaTime) override; // Called every frame
	
	UPROPERTY(EditAnywhere)
	float SpawnTimerRate = 2.0f; // частота создания объектов

	UPROPERTY(EditAnywhere)
	float DestroyTimerRate = 1.0f; // частота удаления объектов
	
	FTimerHandle SpawnTimerHandle; //дескриптор таймера для создания объектов
	
	FTimerHandle DestroyTimerHandle; //дескриптор таймера для удаления объектов

	const int32 TotalTimerCount = 10; // данная переменная будет хранить информацию о максимальной количестве срабатываний таймера.

	int32 CurrentTimerCount = 0;  //текущее число срабатываний.

	UPROPERTY()
	TArray<ACppBaseActor*> SpawnedObjects; // массив объектов, который мы будем заполнять по мере спауна новых объектов.

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACppBaseActor> CppClass; // класс который нужно порождать(надо выбрать в Detail)

	// Sets default values for this actor's properties
	ACppHubActor();

	void OnTimeToSpawn();
	void OnTimeToDestroy();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
