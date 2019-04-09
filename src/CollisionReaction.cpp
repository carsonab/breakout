#include "./CollisionReaction.h"
#include "Math.h"

using namespace Breakout::Collision;

void Bounce(CollisionChannel channel, Object* owner, Object* collidedAgainst, const Hit& hit)
{
    if (owner == nullptr || collidedAgainst == nullptr)
    {
        return;
    }

    channel;

    MovementComponent* ownerMoveCmp = owner->GetComponent<MovementComponent>();
    if (ownerMoveCmp != nullptr)
    {
        ownerMoveCmp->SetVelocity(Reflect(ownerMoveCmp->GetVelocity(), hit.normal));
    }
}

void Break(CollisionChannel channel, Object* owner, Object* collidedAgainst, const Hit& hit)
{
    UNUSED_ARGS(hit);

    if (owner == nullptr || collidedAgainst == nullptr)
    {
        return;
    }

    channel;

    owner->SetDestroy();
}

void Kill(CollisionChannel channel, Object* owner, Object* collidedAgainst, const Hit& hit)
{
    UNUSED_ARGS(hit);

    if (owner == nullptr || collidedAgainst == nullptr)
    {
        return;
    }

    channel;

    collidedAgainst->SetDestroy();
}

bool CollisionReaction::GetCollisionReaction(const std::string& reactionName, CollisionChannel channel, CollisionReactionFunc& outFunc)
{
    channel;
    bool ret = false;

    auto iter = reactionMap.find(reactionName);
    if (iter != reactionMap.end())
    {
        outFunc = iter->second;
        ret = true;
    }

    return ret;
}



CollisionReaction::CollisionReaction() :
     reactionMap(std::map<std::string, CollisionReactionFunc>())
{
    reactionMap["Bounce"] = Bounce;
    reactionMap["Break"]  = Break;
    reactionMap["Kill"]   = Kill;
}