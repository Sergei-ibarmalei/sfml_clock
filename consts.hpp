#ifndef CONSTS_HPP
#define CONSTS_HPP

    enum class block_kind {hour, minute, big, little};

    //Количество блоков часов-минут в циферблате
    const int CIFERBLAT_COUNTS {60};

    //Количество секунд в циферблате
    const int CIFERBLAT_COUNTS_SEC {3600};

    //----------------Большая стрелка---------------------

    //Количество блоков в часовой срелке
    const int NARROW_BIG_COUNTS {16};

    //Сторона блока часовой стрелки
    const float NARROW_BIG_SIDE {10.0f};

    //Половина стороны часовой стрелки
    const float NARROW_BIG_SIDE_HALF {NARROW_BIG_SIDE/2.0f};

    //Смещение блоков часовой стрелки относительно друг друга
    const float NARROW_SHIFT {15.0f};

    //Радиус часовой стрелки
    const float NARROW_BIG_RADIUS {180.0f};
    //----------------------------------------------------



    //------Маленькая стрелка-----------------------------
    const int NARROW_LITTLE_COUNTS {26};

    const float NARROW_LITTLE_RADIUS {375.0f};

    const float NARROW_LITTLE_SHIFT {10.0f};

    const float NARROW_LITTLE_SIDE {5.0f};

    const float NARROW_LITTLE_SIDE_HALF {NARROW_LITTLE_SIDE/2.0f};
    //----------------------------------------------------

   

    const float RADIAN {3.14159f/180.0f};
    
    const int S_W {1000};
    const int S_H {800};

    //-------------Циферблат------------------------------
    //Сторона часового блока
    const float HOUR_SIDE {10};

    //Половина стороны часового блока
    const float HOUR_SIDE_HALF {HOUR_SIDE/2.0f};

    //Сторона минутного блока
    const float MIN_SIDE  {5.0f};


    //Половина стороны минутного блока
    const float MIN_SIDE_HALF {MIN_SIDE/2.0f};

    //const float SEC_SIDE {1.0f}; 
    //----------------------------------------------------

    //Цетр экрана по х
    const float CENTERX {(float)S_W/2.0f};

    //Цетр экрана по у
    const float CENTERY {(float)S_H/2.0f};

    //Радиус циферблата
    const float RADIUS {300.f};

    //Смещение тени относительно блока
    const float SHADOW_SHIFT {2.0f};
    



#endif 