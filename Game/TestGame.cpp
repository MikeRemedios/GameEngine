#include "testGame.h"

void TestGame::Init()
{

	m_mesh = new Mesh("res/models/sphere.obj");
	m_cubeMesh = new Mesh("res/models/crate.obj");
	m_skyboxTexture = new Texture("posx.jpg", "negx.jpg", "posy.jpg", "negy.jpg", "posz.jpg", "negz.jpg");
	m_texture = new Texture("crate_tex.jpg");
	m_material = Material(m_texture, glm::vec3(1, 1, 1));
	m_skyboxMaterial = Material(m_skyboxTexture, glm::vec3(1, 1, 1));
	m_meshRenderer = new MeshRenderer(*m_mesh, m_material);
	m_skyboxRenderer = new MeshRenderer(*m_cubeMesh, m_skyboxMaterial, SkyboxShader::getInstance());

	m_cube.AddComponent(m_meshRenderer);
	m_cube.GetTransform().setPosition(glm::vec3(0, 0, 0));
	

	m_skybox.AddComponent(m_skyboxRenderer);
	m_skybox.GetTransform().setPosition(glm::vec3(0, 0, 0));
	m_skybox.GetTransform().setScale(glm::vec3(100, 100, 100));

	AddToScene(m_skybox);
	AddToScene(m_cube);

}

static float temp = 0;
void TestGame::Update(float delta)
{
	temp += delta / 2;
}

TestGame::~TestGame()
{
	if (m_texture) delete m_texture;
	if (m_mesh) delete m_mesh;
	if (m_meshRenderer) delete m_meshRenderer;
}