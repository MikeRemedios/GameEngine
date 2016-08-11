#include <engine\3DEngine.h>
#include <vector>

class TestGame : public Game
{
public:
	TestGame() {}

	virtual void Init();
	virtual void Update(float delta);
	virtual ~TestGame();

protected:
private:
	TestGame(const TestGame& other) {}
	void operator=(const TestGame& other) {}

	Mesh* m_mesh;
	Mesh* m_cubeMesh;
	Material m_material;
	Material m_skyboxMaterial;
	Texture* m_texture;
	Texture* m_skyboxTexture;
	MeshRenderer* m_skyboxRenderer;
	MeshRenderer* m_meshRenderer;
	GameObject m_cube;
	GameObject m_skybox;
};