#include "ScreenManager.h"

#include "Display.h"

ScreenManager screen;

void ScreenManager::begin()
{

}

void ScreenManager::splash()
{
    display.showMessage("SIEE");
}

void ScreenManager::mainScreen()
{
    display.showMessage("Principal");
}

void ScreenManager::errorScreen(String texto)
{
    display.showMessage(texto);
}

void ScreenManager::update()
{

}
