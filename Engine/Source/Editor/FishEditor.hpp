#ifndef FishEditor_hpp
#define FishEditor_hpp

#include <FishEngine.hpp>
#include <functional>
#include <ReflectClass.hpp>

namespace FishEditor
{
	//class Model;
	//typedef std::shared_ptr<Model> ModelPtr;

	//struct ModelNode;
	//typedef std::shared_ptr<ModelNode> ModelNodePtr;

	class Asset;
	typedef std::shared_ptr<Asset> AssetPtr;

	class AssetImporter;
	typedef std::shared_ptr<AssetImporter> AssetImporterPtr;

	class TextureImporter;
	typedef std::shared_ptr<TextureImporter> TextureImporterPtr;

	class ModelImporter;
	typedef std::shared_ptr<ModelImporter> ModelImporterPtr;

	class NativeFormatImporter;
	typedef std::shared_ptr<NativeFormatImporter> NativeFormatImporterPtr;

	class AssetOutputArchive;
	class AssetInputArchive;
	class SceneOutputArchive;
	
	class SerializedProperty;
	typedef std::shared_ptr<SerializedProperty> SerializedPropertyPtr;
	
	class SerializedObject;
	typedef std::shared_ptr<SerializedObject> SerializedObjectPtr;


	//typedef std::list<Actor> Action;

	class Meta(NonSerializable) Action
	{
	public:
		typedef std::function<void()> Actor;

		void operator += (Actor const& actor)
		{
			m_actors.push_back(actor);
		}

		void operator()() const
		{
			for (auto const & a : m_actors)
			{
				a();
			}
		}

	private:
		std::list<Actor> m_actors;
	};
}

class HierarchyView;

#endif //FishEditor_hpp
