#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy {
    public:
      virtual ~Strategy() {}
      virtual void playStrategy() const = 0;
};

#endif