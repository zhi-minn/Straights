#ifndef SCORE_VIEW_H
#define SCORE_VIEW_H

#include "observer.h"
#include <vector>
#include <memory>

class Player;

class ScoreView : public Observer {
    std::vector<std::shared_ptr<Player>> players;

    public:
      virtual void notify( Subject & whoNotified ) override;

    friend std::ostream &operator<<(std::ostream &, const ScoreView &);
};

std::ostream &operator<<(std::ostream &, const ScoreView &);

#endif