btRigidBody* PhysicsObject::createRigidBody(btCollisionShape* shape, float mass, btVector3 pos, double ry){
  btVector3 localInertia(0,0,0);
  btTransform transform;
  transform.setIdentity();
  transform.setOrigin(pos);
  btQuaternion rot(btVector3(0,1,0), ry*PI/180.0);
  transform.setRotation(rot);
  btDefaultMotionState* myMotionState = new btDefaultMotionState(transform);
  btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,shape,localInertia);
  return new btRigidBody(rbInfo);
}
