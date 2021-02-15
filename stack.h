#define stack_min_capacity 32
#define stack_struct(T)      \
    typedef struct T##_stack \
    {                        \
        T *buf;              \
        size_t capacity;     \
        size_t size;         \
        size_t top;          \
    } T##_stack;

#define stack_init(T)                                 \
    void T##_stack_init(T##_stack *vec)               \
    {                                                 \
        vec->capacity = stack_min_capacity;           \
        vec->buf = malloc(sizeof(T) * vec->capacity); \
        vec->size = 0;                                \
        vec->top = -1;                                \
    }

#define stack_get(T)                                          \
    T T##_stack_get(T##_stack *vec, size_t idx)               \
    {                                                         \
        if (idx < 0 || idx >= vec->size || vec->top == -1)    \
        {                                                     \
            fprintf(stderr, "Index not valid! Exiting...\n"); \
            exit(-1);                                         \
        }                                                     \
        return *(vec->buf + idx);                             \
    }

#define stack_set(T)                                       \
    void T##_stack_set(T##_stack *vec, size_t idx, T data) \
    {                                                      \
        vec->buf[idx] = data;                              \
    }

#define stack_push(T)                                                \
    void T##_stack_push(T##_stack *vec, T data)                      \
    {                                                                \
        if (vec->size == vec->capacity)                              \
        {                                                            \
            vec->capacity *= 2;                                      \
            vec->buf = realloc(vec->buf, sizeof(T) * vec->capacity); \
        }                                                            \
        T##_stack_set(vec, vec->size++, data);                       \
        vec->top++;                                                  \
    }

#define stack_top(T) \
    T T##_stack_top(T##_stack *vec) { return *(vec->buf + vec->top); }

#define stack_size(T) \
    size_t T##_stack_size(T##_stack *vec) { return vec->size; }

#define stack_pop(T)                                         \
    T T##_stack_pop(T##_stack *vec)                          \
    {                                                        \
        if (vec->top == -1)                                  \
        {                                                    \
            fprintf(stderr, "Stack is Empty! Exiting...\n"); \
            exit(-1);                                        \
        }                                                    \
        T x = T##_stack_get(vec, vec->top);                  \
        vec->top--;                                          \
        vec->size--;                                         \
        return x;                                            \
    }

#define stack(T)                                                       \
    stack_struct(T);                                                   \
    stack_init(T) stack_get(T) stack_set(T) stack_push(T) stack_pop(T) \
        stack_top(T) stack_size(T)

/*
stack(T)=>Determines type of stack i.e T
stac_init(&V)=>creates the stack V of type T
stack_get(&V,int index)=>gets the value from the index i.e fond
function
stack_top()
stack_size()
stack_set(&V,int index,T data)=> changes the value at index
stack_push(&V,val)
stack_pop(&V)
*/