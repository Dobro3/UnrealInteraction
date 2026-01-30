// SPDX-License-Identifier: CC-BY-NC-4.0 GitHub@Dobro3 You are free to use, modify, and share this code for non-commercial purposes only. Selling this code or derivatives is not permitted. For details, see: https://creativecommons.org/licenses/by-nc/4.0/

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "InteractionHintComponent.generated.h"

class UInteractHandlerComponent;
class UInteractionComponent;
/**
 * Simple component to show/hide widget for interact hint.
 * This is not a correct way of doing stuff example, just quick gameplay feature.
 */
UCLASS(ClassGroup=(Components), meta=(BlueprintSpawnableComponent))
class INTERACTIONEXAMPLE_API UInteractionHintComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UInteractionHintComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void OnAimChanged(UInteractionComponent* InteractionComponent);
};
