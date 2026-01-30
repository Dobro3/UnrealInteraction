// SPDX-License-Identifier: CC-BY-NC-4.0 GitHub@Dobro3 You are free to use, modify, and share this code for non-commercial purposes only. Selling this code or derivatives is not permitted. For details, see: https://creativecommons.org/licenses/by-nc/4.0/


#include "InteractionHintComponent.h"

#include "InteractHandlerComponent.h"
#include "InteractionHelpers.h"


UInteractionHintComponent::UInteractionHintComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
	/// Default widget.
	static ConstructorHelpers::FClassFinder<UUserWidget> HintWidgetClassFinder(TEXT("/Game/Widgets/InteractHint"));
	if (HintWidgetClassFinder.Succeeded())
	{
		SetWidgetClass(HintWidgetClassFinder.Class);
	}

	SetWidgetSpace(EWidgetSpace::Screen);
	SetDrawAtDesiredSize(true);
}


void UInteractionHintComponent::BeginPlay()
{
	Super::BeginPlay();

	UInteractHandlerComponent* Handler = UInteractionHelpers::TryGetInteractHandler(GetOwner());

	check(IsValid(Handler)); /// shouldn't be like this, but at least some sanity.

	OnAimChanged(Handler->GetCurrentAimer());

	Handler->OnAimChanged.AddUniqueDynamic(this, &ThisClass::OnAimChanged);
}


void UInteractionHintComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UInteractionHintComponent::OnAimChanged(UInteractionComponent* InteractionComponent)
{
	const bool bNewVisibility = IsValid(InteractionComponent);

	SetVisibility(bNewVisibility);
}

