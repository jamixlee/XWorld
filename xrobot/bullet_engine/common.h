#ifndef BULLET_COMMON_H_
#define BULLET_COMMON_H_

#include <memory>

#include "bullet/LinearMath/btTransform.h"
#include "bullet/PhysicsClientC_API.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/vector_angle.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "../utils.h"

namespace xrobot {
    
class Inventory;
class RobotBase;
class World;

namespace bullet_engine {

typedef std::shared_ptr<RobotBase> RobotBaseSPtr;
typedef std::weak_ptr<RobotBase> RobotBaseWPtr;
typedef std::shared_ptr<World> WorldSPtr;
typedef std::weak_ptr<World> WorldWPtr;

constexpr int kCacheSize = 32;
const glm::vec3 kVec3Zero = glm::vec3(0); 
const glm::vec3 kVec3Up = glm::vec3(0,1,0);
const glm::vec3 kVec3Front = glm::vec3(1,0,0);
const glm::vec3 kVec3Right = glm::vec3(0,0,1);

typedef b3PhysicsClientHandle ClientHandle;
typedef b3SharedMemoryCommandHandle CommandHandle;
typedef b3SharedMemoryStatusHandle StatusHandle;

enum SleepState {
    kSleep = eActivationStateSleep,
    kWakeUp = eActivationStateWakeUp,
    kDisableSleeping = eActivationStateDisableSleeping,
    kEnableSleeping = eActivationStateEnableSleeping,
};

enum ComputeState {
    kComputeVelocity = ACTUAL_STATE_COMPUTE_LINKVELOCITY
};

enum ControlModes {
    kTorque = CONTROL_MODE_TORQUE,
    kVelocity = CONTROL_MODE_VELOCITY,
    kPositionVelocity = CONTROL_MODE_POSITION_VELOCITY_PD
};

enum ConstaintTypes {
    kFixed = eFixedType,
    kRevolute = eRevoluteType,
    kPrismatic = ePrismaticType
};

enum JointTypes {
    kRotationMotor,
    kLinearMotor
};

enum LoadingFlags {
    kOBJConcave = FORCE_CONCAVE,
    kURDFSelfCollision = URDF_USE_SELF_COLLISION,
    kURDFSelfCollisionExParents = URDF_USE_SELF_COLLISION_EXCLUDE_ALL_PARENTS,
    kURDFEnableSleeping = URDF_ENABLE_SLEEPING
};

glm::mat4 TransformToMat4(const btTransform& transform);

btTransform TransformFromDoubles(
        const double* position, const double* orientation);

// http://www.opengl-tutorial.org
// Rotation
glm::quat RotationBetweenVectors(
        const glm::vec3 start, const glm::vec3 dest);

}} // namespace xrobot::bullet_engine

#endif // BULLET_COMMON_H_