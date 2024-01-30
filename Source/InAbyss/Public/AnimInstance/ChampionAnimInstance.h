// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ChampionAnimInstance.generated.h"

class USkillComponent;
class UFSMComponent;
/**
 * 
 */
UCLASS()
class INABYSS_API UChampionAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeBeginPlay() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	virtual void PlayAttackMontage();

	virtual void PlayQMontage();
	virtual void PlayWMontage();
	virtual void PlayEMontage();
	virtual void PlayRMontage();
	

	UFUNCTION()
	virtual void AnimNotify_ApplyDamage();
	UFUNCTION()
	virtual void AnimNotify_Q();
	UFUNCTION()
	virtual void AnimNotify_EndAttack();
	UFUNCTION()
	virtual void AnimNotify_EndSkill();

protected:
	UPROPERTY(BlueprintReadOnly, Meta = (AllowPrivateAccess))
	bool bIsMove;
	
	UPROPERTY()
	UFSMComponent* FSMComponent;
	UPROPERTY()
	USkillComponent* SkillComponent;
	

	UPROPERTY(EditDefaultsOnly, Meta = (AllowPrivateAccess))
	UAnimMontage* AttackMontage;
	UPROPERTY(EditDefaultsOnly, Meta = (AllowPrivateAccess))
	UAnimMontage* QMontage;
	UPROPERTY(EditDefaultsOnly, Meta = (AllowPrivateAccess))
	UAnimMontage* WMontage;
	UPROPERTY(EditDefaultsOnly, Meta = (AllowPrivateAccess))
	UAnimMontage* EMontage;
	UPROPERTY(EditDefaultsOnly, Meta = (AllowPrivateAccess))
	UAnimMontage* RMontage;

protected:
	ACharacter* Owner;
};