#ifndef FISH_HPP
#define FISH_HPP

#include "Position.hpp"
#include "Orientation.hpp"
#include "GrowthStep.hpp"
#include "Status.hpp"

class Fish {
    protected:
        static const int MAX_VELOCITY = 6;
        /**
         * Time from Fish eat until starving
         * @todo set constant
         */
        static const int REPLETE_TIME = 12;
        /**
         * Time from Fish starving until die
         * @todo set constant
         */
        static const int STARVATION_TIME = 17;
        static const int FIRST_GROWTH_EAT_COUNTER = 7;
        static const int SECOND_GROWTH_EAT_COUNTER = 15;

        int status;
        Position* position;
        /**
         * Destination of Fish when Fish is idle
         */
        Position* destination;
        int growthStep;
        int orientation;
        int starvingTimer;
        int eatCounter;
        
    public:
        /**
         * Construct Fish
         * Set status to STATUS_IDLE
         * Set position to random new position
         * Set destination to random new position
         * Set growthStep to GROWTH_STEP_ONE
         * Set starvingTimer to zero
         * Set orientation according to destination
         * Set eatCounter to zero
         */
        Fish(int maxWidth, int maxHeight);
        
        /**
         * Getter  
         */
        int getStatus() const;
        Position* getPosition() const;
        Position* getDestination() const;
        int getGrowthStep() const;
        int getStarvingTimer() const;
        int getOrientation() const;
        int getEatCounter() const;

        /**
         * Setter
         */
        void setStatus(int status);
        void setPosition(Position* position);
        void setDestination(Position* position);
        void setGrowthStep(int growthStep);
        void setStarvingTimer(int starvingTimer);
        void setOrientation(int orientation);
              
        virtual bool isProduceCoin()=0;
        
        /**
         * @return {bool} REPLETE TIME <= starvingTimer <= STARVING TIME 
         */
        bool isStarving();
        
        /**
         * Increment eatCounter
         * If exceed minimum eatCounter, upgrade growthStep to next step
         */
        void eat();
        
        /**
         * Move Fish to the dest
         * @param {Position} is the nearest Food for Guppy
         *   or nearest Guppy for Piranha
         */
        void moveToDestination(Position* position);
        
        /**
         * Move Fish to their default destination
         * If Fish Position equal to default destination
         * random new destination 
         */
        void moveToDestination();
};

#endif
