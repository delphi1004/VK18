//
//  JLGlobal.cpp
//  scanner
//
//  Created by jlsy012 on 2018. 2. 19..
//

#include "global.h"

static JLGlob *myThis;

JLGlob* JLGlob::shared()
{
    if (myThis == NULL)
    {
        myThis = new JLGlob();
    }
    
    return myThis;
}
