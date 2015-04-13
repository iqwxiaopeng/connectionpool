#ifndef NOCOPYABLE_H
#define NOCOPYABLE_H


class NonCopyable
{
public:
	NonCopyable() = default;
	~NonCopyable() = default;
private:
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable& operator = (const NonCopyable&) = delete;
};
#endif