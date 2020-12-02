#ifndef SCORE_VIEW_H
#define SCORE_VIEW_H

#include <vector>
#include <memory>

class Player;

class ScoreView {
    std::vector<std::shared_ptr<Player>> players;

    public:
        void setPlayers(std::vector<std::shared_ptr<Player>>);

    friend std::ostream &operator<<(std::ostream &, const ScoreView &);
};

std::ostream &operator<<(std::ostream &, const ScoreView &);

#endif