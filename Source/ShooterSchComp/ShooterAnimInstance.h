// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ShooterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERSCHCOMP_API UShooterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);
	
	virtual void NativeInitializeAnimation() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class AShooterCharacter* ShooterCharacter;

	/**The speed of the character*/
	UPROPERTY(VisibleAnywhere, BlueprintreadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float Speed;
	/*Whether the character is in the air**/
	UPROPERTY(VisibleAnywhere, BlueprintreadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bIsInAir;
	/*whether or not the charater is moving*/
	UPROPERTY(VisibleAnywhere, BlueprintreadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating;

	/*offset used for strafing*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movemnt, meta = (AllowPrivateAccess = "true"))
	float MovementOffsetYaw;
	
	/* The frame we used before character stopped moving used for stop blendspace*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movemnt, meta = (AllowPrivateAccess = "true"))
	float LastMovementOffsetYaw;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bAiming;
};
