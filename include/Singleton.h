class Random
{
public:
  Random(const Random&) = delete;

  static Random& Get()
  {
    static Random instance;
    return instance;
  }

  static float Float() { return Get().IFloat(); }

private:
  Random() {}
  float IFloat() { return m_RandomNumber; }

private:
  float m_RandomNumber = 0.5f;
};

/*

int main()
{
  Random& random = Random::Get();
  std::cout << random.Float() << std::endl;

  std::cout << Random::Float() << std::endl;
}

*/