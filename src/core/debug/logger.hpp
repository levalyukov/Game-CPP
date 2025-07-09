class Logger {
  public:
    static Logger& Instance() {
      static Logger& l;
      return l;
    };

  private:
    Logger() {};
    ~Logger() {};
    Logger (Logger const&) = delete;
    Logger& operator=(Logger const&) = delete;
};
