// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DResourceStruct.generated.h"

USTRUCT(BlueprintType)
struct FDResourceStruct
{
    GENERATED_USTRUCT_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
    FString name;
    
    UPROPERTY(BlueprintReadOnly, Category = "Resource")
    FString uuid;
    
    FDResourceStruct()
    {};
};