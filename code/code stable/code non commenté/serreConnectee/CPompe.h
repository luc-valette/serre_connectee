#include "CActionneur.h"

class CPompe:public CActionneur{
  public:
    CPompe();
    bool valeurPompe();
    void changerValeurActionneur();
  private:
    bool etatPompe;
};