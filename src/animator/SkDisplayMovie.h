
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkDisplayMovie_DEFINED
#define SkDisplayMovie_DEFINED

#include "SkAnimator.h"
#include "SkADrawable.h"
#include "SkMemberInfo.h"

struct SkEventState;

class SkDisplayMovie : public SkADrawable {
    DECLARE_DISPLAY_MEMBER_INFO(Movie);
    SkDisplayMovie();
    virtual ~SkDisplayMovie();
    void buildMovie();
    SkDisplayable* deepCopy(SkAnimateMaker* ) SK_OVERRIDE;
    void dirty() SK_OVERRIDE;
    bool doEvent(const SkEvent& evt) {
        return fLoaded && fMovie.doEvent(evt);
    }
    bool doEvent(SkDisplayEvent::Kind , SkEventState* state ) SK_OVERRIDE;
    bool draw(SkAnimateMaker& ) SK_OVERRIDE;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker* ) SK_OVERRIDE;
    void dumpEvents() SK_OVERRIDE;
#endif
    bool enable(SkAnimateMaker& ) SK_OVERRIDE;
    const SkAnimator* getAnimator() const { return &fMovie; }
    bool hasEnable() const SK_OVERRIDE;
    void onEndElement(SkAnimateMaker& ) SK_OVERRIDE;
protected:
    SkString src;
    SkAnimator fMovie;
    SkBool8 fDecodedSuccessfully;
    SkBool8 fLoaded;
    SkBool8 fMovieBuilt;
    friend class SkAnimateMaker;
    friend class SkPost;
private:
    typedef SkADrawable INHERITED;
};

#endif // SkDisplayMovie_DEFINED
