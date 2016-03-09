#include "homeelement.h"

int HomeElement::s_id = 0;

HomeElement::HomeElement() :
    m_id(s_id)
{
    ++s_id;
}
