// SPDX-License-Identifier: CC-BY-NC-4.0 GitHub@Dobro3 You are free to use, modify, and share this code for non-commercial purposes only. Selling this code or derivatives is not permitted. For details, see: https://creativecommons.org/licenses/by-nc/4.0/


#include "SingleInteractionTester.h"

#include "InteractHandlerComponent.h"
#include "Conditions/Examples/InteractionConditionAlwaysCan.h"
#include "InteractionExample/Components/InteractionHintComponent.h"
#include "InteractionExample/InteractionObjects/Actions/SpawnParticlesAction.h"
#include "Net/UnrealNetwork.h"


ASingleInteractionTester::ASingleInteractionTester()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	InteractableComponent = CreateDefaultSubobject<UInteractHandlerComponent>(TEXT("InteractableComponent"));
	InteractableComponent->SetInteractionCondition(CreateDefaultSubobject<UInteractionConditionAlwaysCan>(TEXT("InteractionConditionAlwaysCan")));
	InteractableComponent->SetInteractionAction(CreateDefaultSubobject<USpawnParticlesAction>(TEXT("SpawnParticlesAction")));

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	SetRootComponent(CubeMesh);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshFinder(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));

	if (CubeMeshFinder.Succeeded())
	{
		CubeMesh->SetStaticMesh(CubeMeshFinder.Object);
	}

	InteractionHint = CreateDefaultSubobject<UInteractionHintComponent>(TEXT("InteractionHintComponent"));
	InteractionHint->SetupAttachment(CubeMesh);
	constexpr float DefaultHintOffset = 100.f;
	InteractionHint->SetRelativeLocation(FVector::UpVector * DefaultHintOffset);
}

void ASingleInteractionTester::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

