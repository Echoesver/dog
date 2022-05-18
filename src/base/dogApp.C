#include "dogApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
dogApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

dogApp::dogApp(InputParameters parameters) : MooseApp(parameters)
{
  dogApp::registerAll(_factory, _action_factory, _syntax);
}

dogApp::~dogApp() {}

void
dogApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"dogApp"});
  Registry::registerActionsTo(af, {"dogApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
dogApp::registerApps()
{
  registerApp(dogApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
dogApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  dogApp::registerAll(f, af, s);
}
extern "C" void
dogApp__registerApps()
{
  dogApp::registerApps();
}
