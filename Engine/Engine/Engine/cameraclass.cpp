#include "cameraclass.h"

CameraClass::CameraClass()
{
    m_positionX = 0.0f;
    m_positionY = 0.0f;
    m_positionZ = 0.0f;

    m_rotationX = 0.0f;
    m_rotationY = 0.0f;
    m_rotationZ = 0.0f;
}

CameraClass::CameraClass(const CameraClass& other)
{

}

CameraClass::~CameraClass()
{

}

void CameraClass::SetPosition(float x, float y, float z)
{
    m_positionX = x;
    m_positionY = y;
    m_positionZ = z;
    return;
}

void CameraClass::SetRotation(float x, float y, float z)
{
    m_rotationX = x;
    m_rotationY = y;
    m_rotationZ = z;
    return;
}

void CameraClass::Render()
{
    D3DXVECTOR3 up;
    D3DXVECTOR3 position;
    D3DXVECTOR3 lookAt;
    float radians;

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;

    // Setup position of camera in world
    position.x = m_positionX;
    position.y = m_positionY;
    position.z = m_positionZ;

    radians = m_rotationY * 0.0174532925f;

    // Setup where camera is looking
    lookAt.x = sinf(radians) + m_positionX;
    lookAt.y = m_positionY;
    lookAt.z = cosf(radians) + m_positionZ;

    D3DXMatrixLookAtLH(&m_viewMatrix, &position, &lookAt, &up);

    return;
}

void CameraClass::GetViewMatrix(D3DXMATRIX& viewMatrix)
{
    viewMatrix = m_viewMatrix;
    return;
}