// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerStatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCANE_ARCHER_API UPlayerStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float hp;
	float max_hp;
	float atk;
	float speed;

	int hp_lvl;
	int atk_lvl;
	int speed_lvl;

	int level_point;

	static const int MAX_LVL = 5;
	static const int MAX_POINT = 3 * (MAX_LVL - 1);

	static float HP_TABLE[MAX_LVL];
	static float ATK_TABLE[MAX_LVL];
	static float SPEED_TABLE[MAX_LVL];

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void giveDamage(float damage) {
		hp -= damage;
	}

	UFUNCTION(BlueprintCallable)
	float getMaxHP() {
		return max_hp;
	}

	UFUNCTION(BlueprintCallable)
	float getAttack() {
		return atk;
	}

	UFUNCTION(BlueprintCallable)
	float getSpeed() {
		return speed;
	}

	UFUNCTION(BlueprintCallable)
	virtual void showStatusManagementScreen();

	UFUNCTION(BlueprintCallable)
	int getHPLevel() {
		return hp_lvl;
	}

	UFUNCTION(BlueprintCallable)
	int getAttackLevel() {
		return atk_lvl;
	}

	UFUNCTION(BlueprintCallable)
	int getSpeedLevel() {
		return speed_lvl;
	}

	UFUNCTION(BlueprintCallable)
	int getRemainingPoints() {
		return level_point - hp_lvl - atk_lvl - speed_lvl;
	}

	UFUNCTION(BlueprintCallable)
	int upgradeHPLevel() {
		if (getRemainingPoints() > 0 && hp_lvl < MAX_LVL - 1) {
			hp_lvl++;
			updateStat();
		}
		return hp_lvl;
	}

	UFUNCTION(BlueprintCallable)
	int upgradeAttackLevel() {
		if (getRemainingPoints() > 0 && atk_lvl < MAX_LVL - 1) {
			atk_lvl++;
			updateStat();
		}
		return atk_lvl;
	}

	UFUNCTION(BlueprintCallable)
	int upgradeSpeedLevel() {
		if (getRemainingPoints() > 0 && speed_lvl < MAX_LVL - 1) {
			speed_lvl++;
			updateStat();
		}
		return speed_lvl;
	}

	UFUNCTION(BlueprintCallable)
	int downgradeHPLevel() {
		if (hp_lvl > 0) {
			hp_lvl--;
			updateStat();
		}
		return hp_lvl;
	}

	UFUNCTION(BlueprintCallable)
	int downgradeAttackLevel() {
		if (atk_lvl > 0) {
			atk_lvl--;
			updateStat();
		}
		return atk_lvl;
	}

	UFUNCTION(BlueprintCallable)
	int downgradeSpeedLevel() {
		if (speed_lvl > 0) {
			speed_lvl--;
			updateStat();
		}
		return speed_lvl;
	}

	UFUNCTION(BlueprintCallable)
	int addLevelPoint(int point) {
		level_point += point;
		if (level_point > MAX_POINT) level_point = MAX_POINT;
		return level_point;
	}

	void updateStat() {
		max_hp = UPlayerStatComponent::HP_TABLE[hp_lvl];
		atk = UPlayerStatComponent::ATK_TABLE[atk_lvl];
		speed = UPlayerStatComponent::SPEED_TABLE[speed_lvl];
		hp = max_hp;
	}
};

