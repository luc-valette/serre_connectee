#include "CActionneur.h"

class CElectrovanne : public CActionneur{
  public :
    CElectrovanne();
    bool valeurElectrovanne();
    void changerValeurActionneur();
  private:
    bool etatElectrovanne;
};