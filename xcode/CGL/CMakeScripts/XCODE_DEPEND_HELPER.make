# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.CGL.Debug:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/src/Debug/libCGL.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/src/Debug/libCGL.a


PostBuild.glew.Debug:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glew/Debug/libglew.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glew/Debug/libglew.a


PostBuild.glfw.Debug:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glfw/src/Debug/libglfw3.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glfw/src/Debug/libglfw3.a


PostBuild.CGL.Release:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/src/Release/libCGL.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/src/Release/libCGL.a


PostBuild.glew.Release:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glew/Release/libglew.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glew/Release/libglew.a


PostBuild.glfw.Release:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glfw/src/Release/libglfw3.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glfw/src/Release/libglfw3.a


PostBuild.CGL.MinSizeRel:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/src/MinSizeRel/libCGL.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/src/MinSizeRel/libCGL.a


PostBuild.glew.MinSizeRel:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glew/MinSizeRel/libglew.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glew/MinSizeRel/libglew.a


PostBuild.glfw.MinSizeRel:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glfw/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glfw/src/MinSizeRel/libglfw3.a


PostBuild.CGL.RelWithDebInfo:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/src/RelWithDebInfo/libCGL.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/src/RelWithDebInfo/libCGL.a


PostBuild.glew.RelWithDebInfo:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glew/RelWithDebInfo/libglew.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glew/RelWithDebInfo/libglew.a


PostBuild.glfw.RelWithDebInfo:
/Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/jamesrazo/desktop/CS184/hw2/p2-meshedit-sp20-Hames1001/xcode/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a




# For each target create a dummy ruleso the target does not have to exist
