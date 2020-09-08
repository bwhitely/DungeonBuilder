TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Core/Creatures/abstractcreature.cpp \
        Core/Creatures/monster.cpp \
        Core/Dungeon/Basic/basicdungeonlevel.cpp \
        Core/Dungeon/Basic/basicdungeonlevelbuilder.cpp \
        Core/Dungeon/Basic/quartzchamber.cpp \
        Core/Dungeon/Basic/rockchamber.cpp \
        Core/Dungeon/Common/blockeddoorway.cpp \
        Core/Dungeon/Common/lockeddoor.cpp \
        Core/Dungeon/Common/onewaydoor.cpp \
        Core/Dungeon/Common/opendoorway.cpp \
        Core/Dungeon/Magical/alchemistslaboratory.cpp \
        Core/Dungeon/Magical/enchantedlibrary.cpp \
        Core/Dungeon/Magical/magicaldungeonlevel.cpp \
        Core/Dungeon/Magical/magicaldungeonlevelbuilder.cpp \
        Core/Dungeon/Magical/magicwall.cpp \
        Core/Dungeon/doorway.cpp \
        Core/Dungeon/dungeonlevel.cpp \
        Core/Dungeon/dungeonlevelbuilder.cpp \
        Core/Dungeon/room.cpp \
        Core/Dungeon/roomedge.cpp \
        Core/Dungeon/wall.cpp \
        Core/Items/consumeable.cpp \
        Core/Items/item.cpp \
        Core/Items/weapon.cpp \
        Core/game.cpp \
        Core/menuinterface.cpp \
        main.cpp

HEADERS += \
    Core/Creatures/abstractcreature.h \
    Core/Creatures/monster.h \
    Core/Dungeon/Basic/basicdungeonlevel.h \
    Core/Dungeon/Basic/basicdungeonlevelbuilder.h \
    Core/Dungeon/Basic/quartzchamber.h \
    Core/Dungeon/Basic/rockchamber.h \
    Core/Dungeon/Common/blockeddoorway.h \
    Core/Dungeon/Common/lockeddoor.h \
    Core/Dungeon/Common/onewaydoor.h \
    Core/Dungeon/Common/opendoorway.h \
    Core/Dungeon/Magical/alchemistslaboratory.h \
    Core/Dungeon/Magical/enchantedlibrary.h \
    Core/Dungeon/Magical/magicaldungeonlevel.h \
    Core/Dungeon/Magical/magicaldungeonlevelbuilder.h \
    Core/Dungeon/Magical/magicwall.h \
    Core/Dungeon/doorway.h \
    Core/Dungeon/dungeonlevel.h \
    Core/Dungeon/dungeonlevelbuilder.h \
    Core/Dungeon/room.h \
    Core/Dungeon/roomedge.h \
    Core/Dungeon/wall.h \
    Core/Items/consumeable.h \
    Core/Items/item.h \
    Core/Items/weapon.h \
    Core/game.h \
    Core/menuinterface.h
