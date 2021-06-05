
import os
env = Environment(ENV = {'PATH': os.environ['PATH']})

src_actor = [
    "source/ermine/actor/eobject.c",
    "source/ermine/actor/eactor.c",
    "source/ermine/actor/eshape_class.c",
    "source/ermine/actor/eshape_rect.c",
    "source/ermine/actor/eshape_circle.c",
    "source/ermine/actor/etexture_class.c",
    "source/ermine/actor/esprite.c",
    "source/ermine/actor/etext_render.c",
]

source = [
    src_actor,
    "source/ermine/system.c",
    "source/ermine/scene.c",
    "source/ermine/stage.c",
    "source/ermine/resource.c",
    "source/ermine/collision.c"
]

env.Append(LIBPATH=['source/ermine/libs/raylib/'])
env.Append(LIBS=['-lraylib','-lpthread','-ldl','-lm'])

env.Append(CPPPATH = ['source/ermine/','source/ermine/include/'])
env.Append(CCFLAGS=['-w','-std=c99'])

env.ParseConfig('pkg-config --cflags --libs glib-2.0 gobject-2.0')

env.Program('ermine-game', ['source/game.c',source])
env.Program('ermine-editor', ['source/editor.c',source])
