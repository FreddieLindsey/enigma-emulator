#ifndef Reflector_h
#define Reflector_h

  class Reflector {
    private:
      int map_size;

    public:
      Reflector(int ALPHABET_SIZE);
      void reflect(int& c);
  };

#endif
