#ifndef Reflector_h
#define Reflector_h

  #include "Constants.hpp"

  class Reflector {
    private:
      int map_size;

    public:
      Reflector(void);
      void reflect(int& c);
  };

#endif
