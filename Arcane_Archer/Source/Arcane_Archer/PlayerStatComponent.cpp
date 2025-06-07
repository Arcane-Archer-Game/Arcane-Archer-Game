// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatComponent.h"

float UPlayerStatComponent::HP_TABLE[5] = { 100.0f, 125.0f, 150.0f, 175.0f, 200.0f };
float UPlayerStatComponent::ATK_TABLE[5] = { 20.0f, 25.0f, 30.0f, 35.0f, 40.0f };
float UPlayerStatComponent::SPEED_TABLE[5] = { 1.0f, 1.2f, 1.4f, 1.7f, 2.0f };

// Sets default values for this component's properties
UPlayerStatComponent::UPlayerStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	hp = 0.0f;
	max_hp = 0.0f;
	atk = 0.0f;
	speed = 0.0f;

	hp_lvl = 0;
	atk_lvl = 0;
	speed_lvl = 0;

	level_point = 0;

	updateStat();

	// ...
}


// Called when the game starts
void UPlayerStatComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UPlayerStatComponent::showStatusManagementScreen() {
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, 
			FString::Printf(TEXT("HP %.1f/%.1f | ATK %.2f | SPEED %.2f"), this->hp, this->max_hp, this->atk, this->speed),
			true);
	}
}


// Called every frame
void UPlayerStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if (GEngine) {
	//	GEngine->AddOnScreenDebugMessage(-1, 0.05f, FColor::Yellow, 
	//		FString::Printf(TEXT("HP %.1f/%.1f | ATK %.2f | SPEED %.2f"), this->hp, this->max_hp, this->atk, this->speed),
	//		true);
	//}
}

