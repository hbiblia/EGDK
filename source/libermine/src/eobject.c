#include "eobject.h"

G_DEFINE_TYPE_WITH_PRIVATE(ErmineObject, ermine_object, G_TYPE_OBJECT);

// -----------------------
// --- INIT-CLASS
// -----------------------
static void ermine_object_class_init(ErmineObjectClass *klass)
{
    GObjectClass *obj = G_OBJECT_CLASS(klass);
}
static void ermine_object_init(ErmineObject *self)
{
    ErmineObjectClass *klass = ERMINE_OBJECT(self);
}

// -----------------------
// --- METHODS
// -----------------------
ErmineObject *ermine_object_new(void)
{
    return g_object_new(ERMINE_TYPE_OBJECT, NULL);
}
