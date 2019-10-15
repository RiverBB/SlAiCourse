﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/SlAiEnemyTaskBase.h"
#include "TimerManager.h"
#include "SlAiEnemyTaskAttackPursuit.generated.h"

/**
 * 
 */
UCLASS()
class SLAICOURSE_API USlAiEnemyTaskAttackPursuit : public USlAiEnemyTaskBase
{
	GENERATED_BODY()

	//重写执行函数
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	//重写任务终止函数
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	void OnAnimationTimerDone();
protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector IsActionFinish;
	//攻击动作结束后的委托
	FTimerHandle TimerHandle;
	
	
};