#ifndef _ENGINE_H_
#define _ENGINE_H_

class Engine
{
    private:
        int horsePower {};
        int cubicCapacity {};

    public:
        Engine(int horesepower, int cubicCapacity);

        // Setters
        void SetHorsePower(int horsePower);
        void SetCubicCapacity(int cubicCapacity);

        // Getters
        int GetHorsePower() const;
        int GetCubicCapacity() const;
        // Print function

        void Print() const {
        };

};
#endif // !_ENGINE_H_

