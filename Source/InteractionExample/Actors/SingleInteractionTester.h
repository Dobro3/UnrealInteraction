// SPDX-License-Identifier: CC-BY-NC-4.0 GitHub@Dobro3 You are free to use, modify, and share this code for non-commercial purposes only. Selling this code or derivatives is not permitted. For details, see: https://creativecommons.org/licenses/by-nc/4.0/

#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "GameFramework/Actor.h"
#include "SingleInteractionTester.generated.h"

class UInteractionHintComponent;
class UInteractHandlerComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class INTERACTIONEXAMPLE_API ASingleInteractionTester : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

public:
	ASingleInteractionTester();

protected:
	virtual UInteractHandlerComponent* GetInteractableComponent_Implementation() const override { return InteractableComponent; }

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	/// Component that is responsible for interaction logic.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UInteractHandlerComponent> InteractableComponent;

	/// Simple mesh for visual representation and collision handling.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UStaticMeshComponent> CubeMesh;

	/// Visual interact hint.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	TObjectPtr<UInteractionHintComponent> InteractionHint;
};
