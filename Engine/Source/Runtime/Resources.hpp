#ifndef Resources_hpp
#define Resources_hpp

#include "FishEngine.hpp"

#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem.hpp>
#include <boost/uuid/uuid.hpp>

#include "ReflectClass.hpp"

namespace FishEngine
{
    typedef boost::filesystem::path Path;

	enum class AssetType
	{
		Unknown,
		Texture,
		Model,
		Shader,
		Material,
		Script,
	};

    enum class SystemDirectoryType
    {
        RootDir,
        ShaderDir,
        TextureDir,
        FontDir,
    };

    class FE_EXPORT Meta(NonSerializable) Resources
    {
    public:
        Resources() = delete;

        //static Object Load(const std::string path);

        static Path shaderRootDirectory()
        {
            return s_rootSystemDirectory / "Engine/Shaders";
        }

        static Path shaderHeaderDirectory()
        {
            return s_rootSystemDirectory / "Engine/Shaders/include";
        }

        static Path textureRootDirectory()
        {
            return s_rootSystemDirectory / "Assets/Textures";
        }

        static Path modelRootDirectory()
        {
            return s_rootSystemDirectory / "Assets/Models";
        }

        static Path fontRootDirectory()
        {
            return s_rootSystemDirectory / "Assets/Fonts";
        }

        static Path exampleRootDirectory()
        {
            return s_rootSystemDirectory / "Example";
        }

        static void SetAssetsDirectory(const Path& path);

        static bool FindAssetFile(const std::string& filename, Path& out_path);

        static bool FindSystemFile(const std::string& filename, Path& out_path);

        static void Init(Path const & path = Path());
		
		static std::map<boost::uuids::uuid, std::shared_ptr<Object>> s_importerGUIDToAsset;

		static std::map<boost::filesystem::path, std::weak_ptr<AssetImporter>> s_pathToImporter;

		static AssetType GetAssetType(Path const & ext);
		
    private:
        friend FishEditor::Inspector;

        static Path s_assetsDirectory;
        static Path s_rootSystemDirectory;
        const static Path s_textureRootDirectory;
    };
}

#endif // Resources_hpp
