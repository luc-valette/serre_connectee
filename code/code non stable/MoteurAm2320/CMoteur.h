#include "CActionneur.h"

class CMoteur : public CActionneur{
  public:
    CMoteur();
    bool valeurMoteur();
    void changerValeurActionneur();
  private:
    bool etatMoteur;
};