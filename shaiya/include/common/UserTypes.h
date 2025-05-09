#pragma once
#include <array>
#include <cstdint>

namespace shaiya
{
    enum struct AuthStatus : uint8_t
    {
        AdminA = 1,
        AdminB,
        AdminC,
        AdminD,
        AdminE,
        None = 11
    };

    enum struct MotionType : uint8_t
    {
        None,
        Walk,
        Run,
        WalkBack,
        WalkLeft,
        WalkRight,
        Wade,
        Swim,
        Jump,
        Death,
        SitDown,
        StandUp,
        Break,
        JumpBack,
        JumpLeft,
        JumpRight,
        Idle1,
        Idle2,
        Climb,
        SelectionScreen,
        VehicleRunMode,
        Vehicle,
        Snowboard,
        TwoHandedAtkMode,
        TwoHandedAttack1,
        TwoHandedAttack2,
        TwoHandedAttack3,
        TwoHandedAttack4,
        TwoHandedDamage,
        TwoHandedRunMode,
        BowAtkMode,
        BowAttack,
        BowDamage,
        BowRunMode,
        OneHandedAtkMode,
        OneHandedAttack1,
        OneHandedAttack2,
        OneHandedAttack3,
        OneHandedAttack4,
        OneHandedDamage,
        OneHandedRunMode,
        DualWieldAtkMode,
        DualWieldAttack1,
        DualWieldAttack2,
        DualWieldAttack3,
        DualWieldAttack4,
        DualWieldDamage,
        DualWieldRunMode,
        SpearAtkMode,
        SpearAttack1,
        SpearAttack2,
        SpearAttack3,
        SpearAttack4,
        SpearDamage,
        SpearRunMode,
        JavelinAtkMode,
        JavelinAttack,
        JavelinDamage,
        JavelinRunMode,
        StaffAtkMode,
        StaffAttack1,
        StaffAttack2,
        StaffDamage,
        StaffRunMode,
        ReverseAtkMode,
        ReverseAttack1,
        ReverseAttack2,
        ReverseAttack3,
        ReverseAttack4,
        ReverseDamage,
        ReverseRunMode,
        KnuckleAtkMode,
        KnuckleAttack1,
        KnuckleAttack2,
        KnuckleAttack3,
        KnuckleAttack4,
        KnuckleDamage,
        KnuckleRunMode,
        DaggerAtkMode,
        DaggerAttack1,
        DaggerAttack2,
        DaggerAttack3,
        DaggerAttack4,
        DaggerDamage,
        DaggerRunMode,
        Cast85,
        Cast86,
        UseSkill87,
        Cast88,
        Cast89,
        UseSkill90,
        Cast91,
        Cast92,
        UseSkill93,
        Cast94,
        Cast95,
        UseSkill96,
        Cast97,
        Cast98,
        UseSkill99,
        Skill100,
        Skill101,
        Skill102,
        Skill103,
        Skill104,
        Skill105,
        Skill106,
        Skill107,
        Skill108,
        Skill109,
        Skill110,
        Beg = 116,
        Victory,
        Laugh,
        Love,
        Greet,
        Clap,
        Defeat,
        Start,
        Insult,
        Provoke
    };

    enum struct ShapeType : uint8_t
    {
        None,
        Chicken = 4,
        Dog,
        Horse,
        Pig,
        Fox = 10,
        Wolf,
        Knight,
        Stealth,
        Disguise = 100,
        Degeneration,
        Transformation,
    };
}
