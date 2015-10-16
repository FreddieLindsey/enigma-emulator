#ifndef PlugBoard_h
#define PlugBoard_h

  class PlugBoard {
    private:
      int map_[26];
    public:
      void encode(char& c);
      void decode(char& c);
  };

#endif
