#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ChaoController.generated.h"

/* Represents the grade of a Chao's ability stat */
UENUM()
enum class EStatGrade : uint8_t
{
    E,
    D,
    C,
    B,
    A,
    S
};

UENUM()
enum class EFruit : uint8_t
{
    Round,
    Triangle,
    Square
};

/* Contains the values that determine the Chao's abilities */
USTRUCT()
struct FChaoStats
{
    // The Chao's swimming ability
    UPROPERTY(meta=(ClampMin="0.0"))
    float Swim;
    // The Chao's flying ability
    UPROPERTY(meta=(ClampMin="0.0"))
    float Fly;
    // The Chao's running ability
    UPROPERTY(meta=(ClampMin="0.0"))
    float Run;
    // The Chao's strength
    UPROPERTY(meta=(ClampMin="0.0"))
    float Power;
    // The Chao's endurance
    UPROPERTY(meta=(ClampMin="0.0"))
    float Stamina;
    // The Chao's luckiness
    UPROPERTY(meta=(ClampMin="0.0"))
    float Luck;
    // The Chao's smartness
    UPROPERTY(meta=(ClampMin="0.0"))
    float Intelligence;
};

/* Contains the values that affect the Chao's behavior */
USTRUCT()
struct FChaoDrives
{
/* Drives that decrease over time */
    
    // When non-zero, causes the Chao to laugh and dance happily; decreases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Joy;
    // When non-zero, causes the chao to tantrum; decreases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Anger;
    // When non-zero, causes the Chao to cry; decreases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Sadness;
    // When non-zero, causes the Chao to shiver; decreases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Fear;
    // When non-zero, unknown; decreases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Surprise;
    // When non-zero, causes the Chao to stand in place with a contented expression; decreases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Relaxation;

/* Drives that increase over time */

    // Chao's drive to sleep; increases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Sleepiness;
    // Chao's drive to act tired; increases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Tiredness; 
    // Chao's drive to seek out food; increases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Hunger; 
    // Chao's drive to mate; increases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float MateDrive; 
    // Chao's drive to perform actions such as using toys and doing animal behaviors; increases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Boredom;
    // Chao's drive to interact with other entities (player, other Chao); increases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Loneliness; 
    // Chao's drive to rest by sitting down; increases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float RestDrive; 
    // Chao's drive to seek out water and move around the garden; increases over time
    UPROPERTY(meta=(ClampMin="0.0", ClampMax="1.0"))
    float Energy;
};

/* Contains the illnesses that can (rarel) affect the Chao */
USTRUCT()
struct FChaoIllnesses
{
    // When negative, causes the Chao to cough
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Cough;
    // When negative, causes the Chao to sneeze
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Cold;
    // When negative, causes the Chao to scratch itself
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Rash;
    // When negative, causes the Chao to stand still with a displeased expression
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float RunnyNose;
    // When negative, causes the Chao to hiccup
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Hiccups;
    // When negative, causes the Chao to hold its stomach in pain
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float StomachAche;
};

/* Contains the values that determine the Chao's personality */
USTRUCT()
struct FChaoPersonality
{
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float NormalCurious;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float CrybabyEnergetic;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float NaiveNormal;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float NormalBigEater;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float NormalCarefree;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Kindness;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Solitude;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Vitality;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Regain;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Skillful;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Charming;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Chatty;
    UPROPERTY(meta=(ClampMin="-1.0", ClampMax="1.0"))
    float Fickle;
};

USTRUCT()
struct FChaoGene
{
    UPROPERTY()
    EStatGrade SwimGrade;
    UPROPERTY()
    EStatGrade FlyGrade;
    UPROPERTY()
    EStatGrade RunGrade;
    UPROPERTY()
    EStatGrade PowerGrade;
    UPROPERTY()
    EStatGrade StaminaGrade;
    UPROPERTY()
    EStatGrade LuckGrade;
    UPROPERTY()
    EStatGrade IntelligenceGrade;

    UPROPERTY()
    EFruit FavoriteFruit;
    UPROPERTY()
    EFruit HatedFruit;
};

/* Base controller for all Chao types. */
UCLASS()
class AChaoBaseController : public AAIController
{
    GENERATED_BODY()

    FChaoStats Stats;
    FChaoDrives Drives;
    FChaoIllnesses Illnesses;
    FChaoPersonality Personality;
    
    FChaoGene MotherGene;
    FChaoGene FatherGene;

public:

    const FChaoStats& GetStats() const { return Stats; }
    FChaoStats& GetStats() { return Stats; }

    const FChaoDrives& GetDrives() const { return Drives; }
    FChaoDrives& GetDrives() { return Drives; }

    const FChaoIllnesses& GetIllnesses() const { return Illnesses; }
    FChaoIllnesses& GetIllnesses() { return Illnesses; }

    const FChaoPersonality& GetPersonality() const { return Personality; }
    FChaoPersonality& GetPersonality() { return Personality; }
    
    const FChaoGene& GetMotherGene() const { return MotherGene; }
    FChaoGene& GetMotherGene() { return MotherGene; }

    const FChaoGene& GetFatherGene() const { return FatherGene; }
    FChaoGene& GetFatherGene() { return FatherGene; }
};
