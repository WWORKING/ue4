// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Persons/DPersonCharacter.h"
#include "Dialogs/DDialogStruct.h"

#include "DPlayableCharacter.generated.h"

/**
 * 
 */
UCLASS()
class OPENDND_API ADPlayableCharacter : public ADPersonCharacter
{
	GENERATED_BODY()
	
    /** Camera boom positioning the camera behind the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* CameraBoom;
    
    /** Follow camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* FollowCamera;
public:
    ADPlayableCharacter();
    
    /** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
    float BaseTurnRate;
    
    /** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
    float BaseLookUpRate;
    
protected:
    
    /** Resets HMD orientation in VR. */
    void OnResetVR();
    
    /** Called for forwards/backward input */
    void MoveForward(float Value);
    
    /** Called for side to side input */
    void MoveRight(float Value);
    
    /**
     * Called via input to turn at a given rate.
     * @param Rate    This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
     */
    void TurnAtRate(float Rate);
    
    /**
     * Called via input to turn look up/down at a given rate.
     * @param Rate    This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
     */
    void LookUpAtRate(float Rate);
    
    /** Handler for when a touch input begins. */
    void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);
    
    /** Handler for when a touch input stops. */
    void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
    
protected:
    // APawn interface
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    // End of APawn interface
    
public:
    /** Returns CameraBoom subobject **/
    FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
    /** Returns FollowCamera subobject **/
    FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
    
    // Properties for the dialog
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dialog")
    AActor* InteractingActor;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dialog")
    FDDialogStruct Dialog;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dialog")
    FDResponseStruct DialogResponse;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dialog")
    FDChoiceStruct DialogChoice1;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dialog")
    FDChoiceStruct DialogChoice2;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dialog")
    FDChoiceStruct DialogChoice3;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dialog")
    FDChoiceStruct DialogChoice4;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dialog")
    FDChoiceStruct DialogChoice5;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dialog")
    FDChoiceStruct DialogChoice6;
    
    // Set current dialog
    UFUNCTION(BlueprintCallable, Category = "Dialog")
    void SetDialogPrompt();
    
    // Start dialog
    UFUNCTION(BlueprintCallable, Category = "Dialog")
    void StartDialog();
    
    // End dialog
    UFUNCTION(BlueprintCallable, Category = "Dialog")
    void EndDialog();
};
