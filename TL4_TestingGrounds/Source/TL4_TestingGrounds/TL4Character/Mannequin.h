// Copyright (c) Shivam Mukherjee 2017

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mannequin.generated.h"


UCLASS()
class TL4_TESTINGGROUNDS_API AMannequin : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMannequin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void UnPossessed() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<class AGun> GunBlueprint;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void PullTrigger();

private:
	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* Mesh1P = nullptr;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	AGun* Gun = nullptr;

};