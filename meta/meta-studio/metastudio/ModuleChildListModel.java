package metastudio;

import java.util.*;
import javax.swing.*;

aspect ModuleChildListModel
{
  private ListListModel Module.childListModel;

  pointcut childAddListener(Module module):
    target(module) &&
    execution(void Module.addChild(String));
    
  after(Module module) : childAddListener(module)
  {
    module.childListModel.elementAdded();
  }
}
