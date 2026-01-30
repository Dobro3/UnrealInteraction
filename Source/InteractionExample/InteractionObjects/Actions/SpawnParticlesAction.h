// SPDX-License-Identifier: CC-BY-NC-4.0 GitHub@Dobro3 You are free to use, modify, and share this code for non-commercial purposes only. Selling this code or derivatives is not permitted. For details, see: https://creativecommons.org/licenses/by-nc/4.0/

#pragma once

#include "CoreMinimal.h"
#include "Actions/InstantInteractAction.h"
#include "SpawnParticlesAction.generated.h"

class UNiagaraSystem;

/**
 * Simple interaction action that just spawns particles.
 */
UCLASS()
class INTERACTIONEXAMPLE_API USpawnParticlesAction : public UInstantInteractAction
{
	GENERATED_BODY()

	virtual void StartInteraction_Implementation(UInteractionComponent* InteractionComponent, UInteractHandlerComponent* InteractHandler) override;

protected:
	/// Niagara system to spawn. Usually should be Soft pointer, but for Demo purpose we will keep it as strong ref.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interaction")
	TObjectPtr<UNiagaraSystem> SystemToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interaction", meta=(MakeEditWidget))
	FVector SpawnOffset = FVector::ZeroVector;
};
