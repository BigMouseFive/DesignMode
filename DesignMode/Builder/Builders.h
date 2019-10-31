#pragma once
#include "Builder.h"

class Builder1 : public Builder {
	virtual void BuildC();
	virtual void BuildS();
	virtual void BuildI();
	virtual void BuildF();
	virtual void BuildD();
};

class Builder2 : public Builder {
	virtual void BuildC();
	virtual void BuildS();
	virtual void BuildI();
	virtual void BuildF();
	virtual void BuildD();
};