// SPDX-License-Identifier: CC-BY-NC-4.0 GitHub@Dobro3 You are free to use, modify, and share this code for non-commercial purposes only. Selling this code or derivatives is not permitted. For details, see: https://creativecommons.org/licenses/by-nc/4.0/


#include "InteractionExample/InteractionObjects/Actions/SpawnParticlesAction.h"

#include "InteractHandlerComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"

void USpawnParticlesAction::StartInteraction_Implementation(UInteractionComponent* InteractionComponent, UInteractHandlerComponent* InteractHandler)
{
	if (IsValid(SystemToSpawn) && IsValid(InteractHandler) && IsValid(InteractHandler->GetOwner()))
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, SystemToSpawn, InteractHandler->GetOwner()->GetActorLocation() + SpawnOffset);
	}

	Super::StartInteraction_Implementation(InteractionComponent, InteractHandler);
}
